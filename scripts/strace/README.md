### Reasoning

Every function has a target "dynamic test command".
For example it could be a call to the test set with a specific unit test.
It could also be a call to execute a binary with a specific set of flags.
The behavior of this call is recorded using `strace`.
All versions' traces are compared against the original trace.


### Implementation
Given a list of build directories (right now we can use the envy-<UUID> dirs),
and a <command>, we run:

`setarch -R strace -c -S calls <build-dir>/<command> > <build-dir>/trace 2>&1`

Then we run a loop through the results and diff tool to get divergence in
'calls', 'syscalls'.
Results go in a csv.
