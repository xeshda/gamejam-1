echo "Do you have SFML Installed? Please enter yes or no"
read n
yes=$(echo $n | tr -s '[:upper:]' '[:lower:]')
if [[  "$n" = "yes"  ]] ; then
   g++ main.cpp -o game -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
   echo "The game has been recompiled. Enjoy."
   sleep 2
   ./game
else
echo -e "\n"
  echo "Please install SFML if the game does not run.
https://www.sfml-dev.org/tutorials/2.5/start-linux.php#installing-sfml"
echo -e "\n"
echo "If you have SFML installed and the game manually does not run either,"
echo -e "\t\t\t\e[4m\e[95mRUN this script once again.\e[0m"
echo -e "\n"
fi
exit
