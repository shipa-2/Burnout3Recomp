# Burnout 3: Takedown — PC port via static recompilation

A very WIP native PC port of *Burnout 3: Takedown*, statically recompiled from the **original Xbox** release (Criterion/EA, EA-091, 2004) — no emulator involved. This is a fork of [mxmstr/Burnout3Recomp](https://github.com/mxmstr/Burnout3Recomp), based on the static recompilation method used by [Unleashed Recompiled](https://github.com/hedge-dev/UnleashedRecomp), using [mxmstr's x86 fork of XenonRecomp](https://github.com/mxmstr/XenonRecomp) as the recompiler (XenonRecomp itself, from [hedge-dev](https://github.com/hedge-dev/XenonRecomp), targets Xbox 360/PowerPC; this fork extends it to the original Xbox's x86).

Upstream's proof-of-concept release ([mxmstr/Burnout3Recomp/releases](https://github.com/mxmstr/Burnout3Recomp/releases)) patches your own legally-dumped `default.xbe` into the final recompiled EXE via a binary diff (`xdelta`), so no copyrighted game code is ever distributed — you supply your own copy. See [`docs/DUMPING-en.md`](docs/DUMPING-en.md) for how to dump it, and [`docs/BUILDING.md`](docs/BUILDING.md) to build from source.

<img width="642" height="512" alt="Burnout 3 title screen, recompiled" src="https://github.com/user-attachments/assets/394e2e44-c5da-4339-8346-52f1cb87c665" />
<img width="642" height="512" alt="Burnout 3 in-game, recompiled" src="https://github.com/user-attachments/assets/b003bf4d-cab1-47c0-8378-7bbb0c511787" />

Confirmed working in this fork: boots to the title screen at a stable 60 FPS with real audio, shaders, and XInput controller support — no emulator. Currently stuck on the animated loading screen before the intro splash; see [Status](#status).

> **Active development moved to [shipa-2/burnout3](https://github.com/shipa-2/burnout3)** (fork of [sp00nznet/burnout3](https://github.com/sp00nznet/burnout3)), an independent, further-along static recompilation of the same binary — full menu rendering, 37 playable tracks, 67 vehicles, its own self-contained toolchain. This repo is kept public because of one thing that took real effort to recover and is worth having around regardless: the previously-missing generated recompiler output (below).

## Status

| Area | Status | Notes |
|---|---|---|
| Binary loaded into Ghidra with full auto-analysis | ✔️ Done | See [Tools](#tools) |
| Microsoft XDK library functions auto-identified | ✔️ Done | 638 of 8308 functions (via XbSymbolDatabase pattern matching) |
| Game-code function names recovered | ✔️ 480 of ~7670 | Already present upstream in `Burnout3RecompLib/x86_func_mapping.cpp` — catalogued here |
| **`Burnout3RecompLib` builds from a fresh clone** | ✔️ **Fixed here** | Upstream declared ~23,591 functions but never committed their bodies (`x86_recomp.*.cpp`, generated locally, likely kept out of git for size) — a fresh clone couldn't link. Regenerated independently via our own build of [mxmstr's x86 XenonRecomp fork](https://github.com/mxmstr/XenonRecomp) against the `burnout3.toml` config already committed there, renamed back to match upstream's naming, verified with a clean standalone build (`cmake` + `ninja`, GCC/Linux) producing `libBurnout3RecompLib.a`. |
| Boots to a native, standalone executable | ✔️ Done | Stable 60 FPS, working audio, shaders, and XInput — no emulator |
| Input subsystem (`CB3InputManager`) | ✔️ Already handled | `hle_xinput.cpp` fully HLEs the Xbox kernel calls it depends on — see [research/notes/input-manager.md](research/notes/input-manager.md) |
| Loading-screen hang before intro splash | 🚧 Diagnosing | See [research/notes/burnout3recomp-loading-hang.md](research/notes/burnout3recomp-loading-hang.md) — leading hypothesis is a synchronous `Kern_NtReadFile` where the game expects an observable pending→complete transition; not yet confirmed with a symbolized debug build |
| Remaining `sub_XXXXXXXX` placeholders | 🚧 ~7187 unnamed | **Already compiling as part of the library** (see above) — what's missing is a human-readable name, not the code itself. Naming/verifying them is a documentation/QA task, not new reverse-engineering |

**8308 total functions** identified by Ghidra's auto-analysis: **638 (7.7%)** are stock Microsoft XDK library code (D3D8, DirectSound, XactEngine, kernel thunks — via XbSymbolDatabase), **480** are Burnout 3's own game code with a real name (already present upstream in `x86_func_mapping.cpp`), leaving **~7187** still to name — all of which already exist as real, compiling, recompiled code (`sub_XXXXXXXX`), not placeholders.

Full raw function inventory (address, name, size, identification source): [`docs/functions.csv`](docs/functions.csv).

**[Function Atlas](https://shipa-2.github.io/Burnout3Recomp/function-atlas.html)** — a squarified treemap of all 8,308 functions (area &prop; byte size), colored by status: grey (untouched), blue (stock Microsoft XDK library code), purple (game code with a recovered name), orange (under active investigation), green (reimplemented and confirmed). Searchable by name/address. Generated by [`research/tools/atlas/build_atlas.py`](research/tools/atlas/build_atlas.py) from `docs/functions.csv`.

## History

This fork's research originally tracked a different approach entirely: reimplementing subsystems as HLE hooks under [Cxbx-Reloaded](https://github.com/Cxbx-Reloaded/Cxbx-Reloaded), via [reburndev/reburn3](https://github.com/reburndev/reburn3). That work is preserved in `research/notes/` for reference. It was dropped in favor of building directly on upstream Burnout3Recomp — real instruction-level static recompilation to a native executable, already far more mature and properly licensed (GPL-3.0) than assumed going in. Full account in [research/ROADMAP.md](research/ROADMAP.md).

## Legal / What's here

- **No game assets, no XBE, no ISO** are committed anywhere in this repository, and never will be. You need your own legally-owned copy of Burnout 3: Takedown (Xbox) — see [`docs/DUMPING-en.md`](docs/DUMPING-en.md).
- `docs/functions.csv` contains only addresses, function names, and sizes — no code, no copyrighted text.
- Verify your own dump against the original release before reporting mismatched addresses:
  - `default.xbe`: 4,308,992 bytes, "Burnout 3" (EA-091), NTSC-U/regions: NA

## Tools

The Ghidra setup used to produce `docs/functions.csv`:

1. **[Ghidra](https://ghidra-sre.org/)** (tested: 12.1.2) with the **[ghidra-xbe](https://github.com/XboxDev/ghidra-xbe)** extension (XBE loader + library symbol recovery), built from source against the installed Ghidra version:
   ```bash
   git clone https://github.com/XboxDev/ghidra-xbe.git && cd ghidra-xbe
   wget -O /tmp/xtlid.xml https://github.com/XboxDev/xtlid/releases/download/v0.1.2/xtlid.xml
   xsltproc -o src/main/java/XbeLoader/XbeXtlidDb.java xtlid2java.xslt /tmp/xtlid.xml
   # Optional but recommended: bundle XbSymbolDatabaseCLI for your OS from
   # https://github.com/Cxbx-Reloaded/XbSymbolDatabase/releases into os/<platform>/
   gradle -PGHIDRA_INSTALL_DIR=<path to Ghidra install>
   # Install the resulting dist/*.zip via Ghidra's "File -> Install Extensions",
   # or unzip it directly into <Ghidra user settings dir>/Extensions/
   ```
2. **[XbSymbolDatabase](https://github.com/Cxbx-Reloaded/XbSymbolDatabase)** — the same OOVPA pattern-matching database Cxbx-Reloaded itself uses for HLE, bundled into the Ghidra extension above. It only recognizes **Microsoft XDK library code**, not RenderWare or game-specific functions.
3. Import `default.xbe`, run auto-analysis. The `Xbox Symbol Database Analyzer` and `Xbox XTLID Symbol ID Analyzer` passes do the library identification.
4. `research/tools/ghidra-xbe/scripts/ExportFunctions.java` — headless script used to generate `docs/functions.csv`.
5. `research/tools/ghidra-xbe/scripts/CheckAddr.java` — quick lookup of a function at a given address, with its resolved symbol.
6. `research/tools/community-names/import_burnout3recomp_names.py` — merges real game-code function names from `Burnout3RecompLib/x86_func_mapping.cpp` into `docs/functions.csv` (only filling in names not already identified as library code).

Run headless (no GUI needed):
```bash
analyzeHeadless <project-dir> <project-name> -import default.xbe -analysisTimeoutPerFile 300
analyzeHeadless <project-dir> <project-name> -process default.xbe -noanalysis \
  -scriptPath research/tools/ghidra-xbe/scripts -postScript ExportFunctions.java
```

## How to document a finding

1. Identify the function's address and role — check `docs/functions.csv` first (it may already be named), then Ghidra decompilation for anything still unnamed.
2. Write up: address, what it does, what it calls, what depends on it. New note goes in `research/notes/`.
3. The actual code change (reimplementing a `sub_XXXXXXXX` placeholder, fixing an HLE bug) is a normal commit/PR against this repo — link back to it from your research note.
4. Validate by actually running the recompiled executable before marking anything "done".

## Credits

This fork builds on **[mxmstr/Burnout3Recomp](https://github.com/mxmstr/Burnout3Recomp)** — a true static recompiler turning this exact retail binary into a standalone native executable ("Developed with the assistance of Claude", per upstream), built on **[mxmstr's x86 fork of XenonRecomp](https://github.com/mxmstr/XenonRecomp)**. Huge thanks for doing the actual hard work of full instruction-level recompilation and function naming — the `research/` directory in this fork only adds a Ghidra cross-check and a catalogue of what's already there.
