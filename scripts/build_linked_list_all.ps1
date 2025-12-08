# Build all Singly Linked List versions
Write-Host "=== Building All Linked List Versions ==="
Write-Host "=== Building All Linked List Versions ==="
$BuildDir = Join-Path $PSScriptRoot "../build"

if (-not (Test-Path -Path $BuildDir)) { New-Item -ItemType Directory -Path $BuildDir | Out-Null }
Push-Location $BuildDir

if (-not (Test-Path -Path "CMakeCache.txt")) { cmake .. }

$Targets = @("ll_01_student", "ll_02_pedagogic", "ll_03_industry", "ll_04_embedded", "ll_05_concurrent")

foreach ($t in $Targets) {
    Write-Host "Building $t..."
    cmake --build . --target $t
}

Pop-Location
