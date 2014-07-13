if [ $# -ne 1 ]; then
  echo 'usage sh qpscript.sh desc-file' >&2
  exit 1
fi
cp "$1" junk-desc-backup.txt
sed '/^\/\/[A-Z ]*$/d' "$1" | sed 's/</\&lt;/g' | sed 's/>/\&gt;/g' | sed -n '1,/^DEFINITION/p' | tfill | sed 's/^ *$/<p>/' | sed '/^DEFINITION/d' > junk.html
echo "<pre>" >> junk.html

sed '/^\/\//d' "$1" | sed 's/</\&lt;/g' | sed 's/>/\&gt;/g' | sed '/^#/d' | sed -n '/^DEFINITION/,$p' >> junk.html

awk 'BEGIN { lnf = 1 }
     { if (NF != 0 && lnf == 0) print ""; if (NF != 0) print $0; lnf = NF }' junk.html > "$1"
