set title 'RC circuit versus time'
set xlabel 'Time (s)'
set ylabel 'E (V), DerE (V), Uc/DerE (V), Uc (V)'
plot 'data.txt' using 1:4 with lines title 'E', '' using 1:7 with lines title 'DerE','' using 1:9 with lines title 'Uc/DerE','' using 1:6 with lines title 'Uc'
pause mouse close
