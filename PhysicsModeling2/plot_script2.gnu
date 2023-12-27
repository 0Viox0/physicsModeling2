set title 'E with DerE and IntE'
set xlabel 'Time (s)'
set ylabel 'E (V),Ur/IntE (V), Ur (V), IntE (V)'
plot 'data.txt' using 1:4 with lines title 'E', '' using 1:10 with lines title 'Ur/IntE','' using 1:5 with lines title 'Ur','' using 1:8 with lines title 'IntE'
pause mouse close
