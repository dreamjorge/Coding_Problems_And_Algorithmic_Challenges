# Helper function to build a specific target
param (
    [string]$TargetName,
    [string]$ProjectName
)

Write-Host "=== Building $ProjectName ($TargetName) ==="
$BuildDir = Join-Path $PSScriptRoot "../build"

if (-not (Test-Path -Path $BuildDir)) {
    New-Item -ItemType Directory -Path $BuildDir | Out-Null
}

Push-Location $BuildDir

# Configure (if needed)
if (-not (Test-Path -Path "CMakeCache.txt")) {
    Write-Host "Configuring CMake..."
    cmake ..
    if ($LASTEXITCODE -ne 0) { Write-Error "CMake Configuration Failed"; exit 1 }
}

# Build specific target
Write-Host "Building Target: $TargetName..."
cmake --build . --target $TargetName
if ($LASTEXITCODE -ne 0) { Write-Error "Build Failed"; exit 1 }

# Run
$PossiblePaths = @(
    "./bin/$TargetName.exe",
    "./bin/Debug/$TargetName.exe",
    "./bin/Release/$TargetName.exe"
)

$ExePath = $null
foreach ($path in $PossiblePaths) {
    if (Test-Path $path) {
        $ExePath = $path
        break
    }
}

if ($ExePath) {
    Write-Host "Running $TargetName (found at $ExePath)..."
    & $ExePath
}
else {
    Write-Error "Executable not found for $TargetName"
}

Pop-Location
