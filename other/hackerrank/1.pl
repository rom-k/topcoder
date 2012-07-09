#!perl

while(<DATA>) {
    print join "", map {/\w/?chr(ord($_)-3):$_} split //, $_;
}

__DATA__
Iuhg Fduo, Mu.
vla wkrxvdqg, irxu kxqguhg dqg iliwb-qlqh
