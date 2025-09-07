:: File:        build-windows.bat
:: Project:     prune
:: Repository:  https://github.com/nessbe/prune
::
:: Copyright (c) 2025 nessbe
:: Licensed under the Apache License, Version 2.0 (the "License");
:: You may not use this file except in compliance with the License.
:: You may obtain a copy of the License at:
::
::     https://www.apache.org/licenses/LICENSE-2.0
::
:: Unless required by applicable law or agreed to in writing, software
:: distributed under the License is distributed on an "AS IS" BASIS,
:: WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
:: See the License for the specific language governing permissions and
:: limitations under the License.
::
:: For more details, see the LICENSE file at the root of the project.

@echo off

set SOURCE="source\prune.c"
set INCLUDE="include"
set FLAGS=-Wall -Wextra
set OUT="build\prune.exe"

where gcc >nul 2>&1

if %errorlevel% neq 0 (
    echo Error: gcc not found in the PATH.
    exit /b 1
)

gcc -I "%INCLUDE%" "%SOURCE%" -o "%OUT%" %FLAGS%

if %errorlevel% neq 0 (
    echo Error: Build failed.
    exit /b 1
) else (
    echo Build succeeded: %OUT%.
)

exit /b 0
