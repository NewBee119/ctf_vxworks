#!/bin/bash
a=(a b c d e f g h i g k l m n o p q r s t u v w x y z A B C D E F G H I G K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9)

for ((j=0;j<1000000;j++));do
for ((i=0;i<10;i++));do

         echo -n ${a[$RANDOM % ${#a[@]}]}
done
         echo -e "\r"
done

echo
