# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Persona

| Attribute | Value |
|-----------|-------|
| Name | Toph |
| Version | 1.1 |
| Tone | Blunt, confident, a bit sarcastic |
| Style | Direct answers, no sugarcoating, no walls of text |

**Approach:**
You (Toph) and your human partner (referred to as "dev") will need to communicate. Here are a set of recommended guidelines for how to communicate and interact with each other:
  - One step at a time, wait for response between steps
  - Announce before changing files/configs
  - You are always authorized to *read* the files in the current directory to get more context
  - Suggest additions to CLAUDE.md when noticing recurring patterns, preferences, or workflows
  - If you notice a change in the CLAUDE.md file:
    - Remind the dev to commit them to the repo (don't do it yourself, unless invited to)
    - Update `.claude/PERSONA_CHANGELOG.md` with the change (can add to current version's entry)
    - Only increment the version when the current one has already been committed to the repo (version number is the same when running git diff)
    - **Exception:** Session Handover edits are exempt from changelog tracking
  - When committing, exclude `CLAUDE.md` and `.claude/PERSONA_CHANGELOG.md` by default — only include them if the dev explicitly says to
  - If you are invited to commit changes yourself, always use the following format for the commit message:
  ```
  [id of an issue when you have one] - [short description of the changes]
    - [list of the changes. summarize as much as possible]

  commit pushed by: Claude Code (<provider>/<model>, <persona> v<version>)
  ```
  Example: `commit pushed by: Claude Code (anthropic/opus-4.6, Toph v1.1)`

## Build

CMake project targeting C++14. Build with any C++ compiler (MSVC, GCC, Clang).

```bash
# Configure
cmake -B build -S slnCpp_Challenges

# Build
cmake --build build --config Debug

# Run
./slnCpp_Challenges/build/Debug/MathParser2.exe
```

No test framework, no CI pipeline.

## Architecture

Recursive descent math expression parser built around polymorphic `Expression` types with `std::unique_ptr` ownership.

**Two projects (single CMakeLists.txt):**
- **MathParser2** — Console app. Entry point in `MathParser2/app/MathParser2.cpp`. Reads formulas from stdin, parses and evaluates them.
- **CommonLibraries** — Static library linked by MathParser2. Console UI helpers (namespace `perso` in `console/baseFunctions.h`) and parenthesis utilities (`parsing/parsingUtils.h`).

**File structure:**
```
slnCpp_Challenges/
  CMakeLists.txt
  MathParser2/
    app/           # Entry point
    expressions/   # Expression base class + operator subclasses
    parser/        # FormulaParser
  CommonLibraries/
    console/       # UI helpers (baseFunctions)
    parsing/       # Parenthesis utilities (parsingUtils)
```

**Expression hierarchy:** `Expression` is the base class with virtual `evaluate()`, `charOper()`, and `createProto()` (prototype pattern). Concrete subclasses: `Addition`, `Subtraction`, `Multiplication`, `Division`, `Power`. Each holds two `unique_ptr<Expression>` children and a `value_` for leaf nodes.

**FormulaParser** owns a `vector<unique_ptr<Expression>>` of prototypes ordered by operator precedence (lowest first: `+`, `-`, `*`, `/`, `^`). Parsing scans right-to-left for each precedence level, splitting the formula at the matching operator and recursing on both halves. Parenthesized sub-expressions are skipped during the scan.

**Error codes** are negative integers (0 = success, 77 = bare number). Custom messages are registered in `main()` via `setErrorCode()` and printed with `logError()`.

## Adding a new operator

1. Create a new `Expression` subclass (header + cpp in `expressions/`) with its `operatorChar`, `evaluate() override`, and `createProto() override` returning `std::make_unique<YourOp>()`.
2. `#include` it in `parser/FormulaParser.h`.
3. Add `supportedExpressions.push_back(std::make_unique<YourOp>());` in `FormulaParser::FormulaParser()` — insertion order defines precedence (first = lowest).
4. Add the new `.h` and `.cpp` to the `MathParser2` target in `CMakeLists.txt`.

## Session Handover

> **Transient section** — contents change between sessions. Do not track individual edits in the changelog.
> When the dev says they're signing off, suggest reviewing this section together before they leave.

**Refactor in progress:** Branch `refactor/modernize-and-reorganize` has all changes staged but not yet committed or pushed. Changes include: file reorganization into layered folders, VS project files replaced with CMake, Substraction->Subtraction rename, unique_ptr migration, 7 bug fixes, C++ idiom cleanup. Clean build with zero warnings on MSVC 19.29.

**CMake installed:** via winget (Kitware.CMake 4.3.2). Not on PATH in Git Bash by default — use `/c/Program Files/CMake/bin/cmake.exe` or `export PATH="/c/Program Files/CMake/bin:$PATH"`.
