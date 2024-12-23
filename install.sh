#!/bin/bash
chmod +x includes/build.sh
bash includes/build.sh
g++ main.cpp levels/newGame.cpp src/variables.cpp levels/scores.cpp src/draw.cpp levels/startUp.cpp levels/levels.cpp src/schemes.cpp levels/facts.cpp levels/instructions.cpp src/functions.cpp levels/storyline.cpp -Iincludes -lsqlite3 -o encrypto
mkdir /opt/encrypto
cp -r * /opt/encrypto/
ln -s /opt/encrypto/encrypto /bin/encrypto
echo "Installation complete."
echo "type 'encrypto' to run the game."
