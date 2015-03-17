#!/usr/bin/perl
# Author: Meng, Chao-Hong (MnO2)
# Email: mno2.111@gmail.com

use strict;
use warnings;
use utf8;
use open ":encoding(utf8)";
use POSIX;

binmode(STDIN, ":encoding(utf8)");
binmode(STDOUT, ":encoding(utf8)");
binmode(STDERR, ":encoding(utf8)");

my $N = 50000;
my $i;
my $c;
my $t1;
my $t2;

print "$N\n";
for ($i = 1; $i <= $N; $i++) {
    print "0 ";
    #print floor($i / 2);
    #print " ";
}
print "\n";

my @commands = ();
my $M = 0;

while ($M < 2*$N) {
    my $coin = int(rand(10));
    if ($coin < 7) {
        $t1 = int(rand($N)) + 1;
        $t2 = int(rand($N+1));

        $c = "MOVE $t1 $t2";
        push @commands, $c;
        $M++;
    } else {
        $t1 = int(rand($N)) + 1;

        $c = "QUERY $t1";
        push @commands, $c; 
        $M++;
    }
}

print "$M\n";
foreach my $c (@commands) {
    print "$c\n";
}
