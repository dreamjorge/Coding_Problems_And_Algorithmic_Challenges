# Run ALL Python Implementations
Write-Host "=== Running All Python Versions ==="
$ScriptDir = $PSScriptRoot
$Root = Join-Path $ScriptDir ".."

# Helper to run a python file
function Run-Py($Path) {
    if (Test-Path $Path) {
        Write-Host ">>> Running $Path"
        python $Path
        if ($LASTEXITCODE -ne 0) { Write-Error "Python script failed." }
    }
    else {
        Write-Error "File not found: $Path"
    }
}

# Dynamic Array
Write-Host "`n--- Dynamic Array ---"
Run-Py (Join-Path $Root "design_dynamic_array/01_student_intro/python/main.py")
Run-Py (Join-Path $Root "design_dynamic_array/02_pedagogic_oop/python/main.py")
Run-Py (Join-Path $Root "design_dynamic_array/03_industry_std/python/main.py")
Run-Py (Join-Path $Root "design_dynamic_array/04_embedded_fixed/python/main.py")
Run-Py (Join-Path $Root "design_dynamic_array/05_concurrent_safe/python/main.py")

# Linked List
Write-Host "`n--- Singly Linked List ---"
Run-Py (Join-Path $Root "design_singly_linked_list/01_student_intro/python/main.py")
Run-Py (Join-Path $Root "design_singly_linked_list/02_pedagogic_oop/python/main.py")
Run-Py (Join-Path $Root "design_singly_linked_list/03_industry_std/python/main.py")
Run-Py (Join-Path $Root "design_singly_linked_list/04_embedded_fixed/python/main.py")
Run-Py (Join-Path $Root "design_singly_linked_list/05_concurrent_safe/python/main.py")

Write-Host "`n=== Done ==="
