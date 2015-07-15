#!/usr/bin/perl

print "Enter expression: ";
$exp = <STDIN>;
chomp($exp);

if ($exp =~ m/a{1}(b+)/) {
   print "$exp has one \"a\" followed by one or more \"b\"\n";
   
   print "These are the b's $1\n";
} 

else {
   print "doesnt have pattern\n";

}
