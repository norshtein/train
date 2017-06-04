for ((i=0;i < 20;i++))
do
  ./gen >"input$i.txt"
  ./ans <"input$i.txt" >"ans$i.txt"
  ./my < "input$i.txt" >"my$i.txt"
  diff "ans$i.txt" "my$i.txt"

  if [ $? -eq 1 ]
  then
    echo "Failed at test case $i"
  else
    echo "Accepted at test case $i"
  fi
done
