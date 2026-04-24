# PowerShell script to rename recompiled functions based on map file symbols
# Usage: .\rename_functions.ps1

$mapFilePath = "C:\Users\lynch\Documents\reburn3\Quake_2x_LE\Quake2x.xbe.map"
$recompiledDir = "."

# Check if map file exists
if (-not (Test-Path $mapFilePath)) {
    Write-Error "Map file not found: $mapFilePath"
    exit 1
}

Write-Host "Loading map file: $mapFilePath"

# Parse the map file to extract function addresses and names
$symbolMap = @{}
$inPublicsSection = $false

Get-Content $mapFilePath | ForEach-Object {
    $line = $_.Trim()
    
    # Check if we're in the "Publics by Value" section
    if ($line -match "Address\s+Publics by Value") {
        $inPublicsSection = $true
        return
    }
    
    # Skip until we reach the publics section
    if (-not $inPublicsSection) {
        return
    }
    
    # Parse lines in format: " 0001:00011240       CB3AsyncDataLoader__QueueLoadRequest"
    if ($line -match '^\s*\d+:([0-9A-Fa-f]{8})\s+(\S.*)$') {
        $address = $matches[1].ToUpper()
        $symbolName = $matches[2].Trim()
        
        # Skip symbols that start with "sub_" or internal symbols
        if ($symbolName -match '^(sub_|def_|jpt_|nullsub_|asc_|byte_|word_|dword_|qword_|loc_|unk_)') {
            return
        }
        
        # Remove leading zeros from address for matching (11240 instead of 00011240)
        $addressNoLeadingZeros = $address -replace '^0+', ''
        if ($addressNoLeadingZeros -eq '') {
            $addressNoLeadingZeros = '0'
        }
        
        # Replace special characters with underscores for C++ compatibility
        # Replace characters that are invalid in C++ identifiers
        $cleanSymbolName = $symbolName -replace '[^a-zA-Z0-9_]', '_'
        
        # Ensure the name doesn't start with a digit
        if ($cleanSymbolName -match '^\d') {
            $cleanSymbolName = "_$cleanSymbolName"
        }
        
        $symbolMap[$addressNoLeadingZeros.ToUpper()] = $cleanSymbolName
        
        Write-Verbose "Mapped 0x$addressNoLeadingZeros -> $cleanSymbolName (original: $symbolName)"
    }
}

Write-Host "Loaded $($symbolMap.Count) symbols from map file"

if ($symbolMap.Count -eq 0) {
    Write-Warning "No symbols found in map file. Please check the file format."
    Write-Host "`nShowing first 20 lines of map file for reference:"
    Get-Content $mapFilePath -First 20 | ForEach-Object { Write-Host $_ }
    exit 1
}

# Get all recompiled C++ file
$cppFiles = Get-ChildItem -Path $recompiledDir -Filter "*.h" -File

$totalRenamed = 0
$filesModified = 0

foreach ($file in $cppFiles) {
    Write-Host "`nProcessing $($file.Name)..."
    
    $content = Get-Content $file.FullName -Raw
    $originalContent = $content
    $renamedInFile = 0
    
    # Find all function definitions matching pattern: X86_FUNC_IMPL(sub_XXXXX) or sub_XXXXX(
    $pattern = '\bsub_([0-9A-Fa-f]+)\b'
    
    $matches = [regex]::Matches($content, $pattern)
    
    # Group matches by address to avoid duplicate messages
    $addressesProcessed = @{
    }
    
    foreach ($match in $matches) {
        $address = $match.Groups[1].Value.ToUpper()
        $oldName = "sub_$($match.Groups[1].Value)"
        
        # Skip if we've already processed this address in this file
        if ($addressesProcessed.ContainsKey($address)) {
            continue
        }
        
        # Check if we have a symbol for this address
        if ($symbolMap.ContainsKey($address)) {
            $newName = $symbolMap[$address]
            
            # Replace ALL occurrences of the old function name with the new one
            # Use word boundaries to ensure we only replace exact matches
            $pattern = "\b$([regex]::Escape($oldName))\b"
            $newContent = $content -replace $pattern, $newName
            
            if ($newContent -ne $content) {
                $content = $newContent
                Write-Host "  0x$address : $oldName -> $newName"
                $renamedInFile++
                $totalRenamed++
                $addressesProcessed[$address] = $true
            }
        }
    }
    
    # Write back to file if changes were made
    if ($content -ne $originalContent) {
        Set-Content -Path $file.FullName -Value $content -NoNewline
        $filesModified++
        Write-Host "  Renamed $renamedInFile unique function(s) in $($file.Name)" -ForegroundColor Green
    }
}

Write-Host "`n========================================="
Write-Host "Summary:"
Write-Host "  Total symbols in map: $($symbolMap.Count)"
Write-Host "  Total unique functions renamed: $totalRenamed"
Write-Host "  Files modified: $filesModified"
Write-Host "=========================================`n"

# Show first few mappings as examples
Write-Host "Example mappings:"
$symbolMap.GetEnumerator() | Select-Object -First 10 | ForEach-Object {
    Write-Host "  0x$($_.Key) -> $($_.Value)"
}

if ($totalRenamed -gt 0) {
    Write-Host "`nRenaming completed successfully!" -ForegroundColor Green
    Write-Host "All function definitions AND calls have been renamed." -ForegroundColor Cyan
} else {
    Write-Host "`nNo functions were renamed. This might mean:" -ForegroundColor Yellow
    Write-Host "  - The addresses in the recompiled files don't match the map file"
    Write-Host "  - The functions have already been renamed"
    Write-Host "  - The map file format is different than expected"
}
