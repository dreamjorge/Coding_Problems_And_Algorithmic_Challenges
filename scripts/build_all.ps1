# Build and Test ALL Projects
Write-Host "=== Building All Projects ==="
# Build and Test ALL Projects
Write-Host "=== Building All Projects ==="
$BuildDir = Join-Path $PSScriptRoot "../build"

if (-not (Test-Path -Path $BuildDir)) {
    New-Item -ItemType Directory -Path $BuildDir | Out-Null
}

Push-Location $BuildDir

# Configure
Write-Host "Configuring CMake..."
cmake ..
if ($LASTEXITCODE -ne 0) { Write-Error "CMake Configuration Failed"; exit 1 }

# Build
Write-Host "Building All Targets..."
cmake --build .
if ($LASTEXITCODE -ne 0) { Write-Error "Build Failed"; exit 1 }

# Test
Write-Host "Running Tests..."
ctest -C Debug --output-on-failure
if ($LASTEXITCODE -ne 0) { Write-Error "Tests Failed"; exit 1 }

Pop-Location
Write-Host "=== Success! All projects built and tested. ==="
