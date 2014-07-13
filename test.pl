#!/usr/bin/env perl
#Opens file for reading
open (FIle, "myfile.txt") or die ("not found");
while (<FILE>){
    print $_; #read each file content
}
close (FILE);
