cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | cut -d ':' -f 1 | rev | sort -r | sed -n ""$FT_LINE1","$FT_LINE2"P" | sed 's/$/,/' | tr -d \\n | sed 's/,/, /g' | sed 's/,.$/./' | tr -d \\n
