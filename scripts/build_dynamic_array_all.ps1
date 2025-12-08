# Build all Dynamic Array versions
Write-Host "=== Building All Dynamic Array Versions ==="
Write-Host "=== Building All Dynamic Array Versions ==="
$BuildDir = Join-Path $PSScriptRoot "../build"

if (-not (Test-Path -Path $BuildDir)) { New-Item -ItemType Directory -Path $BuildDir | Out-Null }
Push-Location $BuildDir

if (-not (Test-Path -Path "CMakeCache.txt")) { cmake .. }

$Targets = @("01_student_intro", "02_pedagogic_oop", "03_industry_std", "04_embedded_fixed", "05_concurrent_safe")

foreach ($t in $Targets) {
    Write-Host "Building $t..."
    cmake --build . --target $t
}

Pop-Location
