open (FIle, "myfile.txt") or die ("not found");
while (<FILE>){
    print $_;
}
