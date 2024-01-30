This project contains two different ideas for mixing different fixtures into one target fixture - virtual inheritance and Mix-Ins.

### Requirements:
1. GTest installed system-wide

### Compilation:
1. Configure with cmake
2. There are three targets: `in-place-test`, `mixin-fixture-test` and `virt-inheritance-fixture-test`

### File structure

Directories show different approach to solving issue of combining multiple orthogonal resources to the test.

* First is just cop-pasting or straight inheritance. You can see it in [in-place-fixture](in-place-fixture) directory.
* Second is virtual inheritance of multiple partial fixtures which derive from `testing::Test`. You can see it in [virtual-inheritance-fixture](virtual-inheritance-fixture) directory.
* The final approach use Mix-In idea implemented with CRTP pattern. You can see it in [mixin-fixture](mixin-fixture) directory.
