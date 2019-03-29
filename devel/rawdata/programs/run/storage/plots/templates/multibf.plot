set terminal pngcairo size 1400, 1200
set output 'stacking.png'
set lmargin at screen 0.08
set rmargin at screen 0.95
TOP=0.95
DY = 0.22
plot=52

set multiplot
unset key
set xrange[0.15:1.5]
set xtics font ",24"
set ytics font ",24"
set offset 0,0,graph 0.05, graph 0.05

set xlabel '{/Symbol D}Y, Rapidity' offset 0,-2 enhanced font ",26"
set ylabel 'KK' offset -3 font ",32"
set ytics ("-0.1" -0.1,"0" 0,"0.1" 0.1,"0.2" 0.2,"0.3" 0.3)
set tmargin at screen TOP-3*DY
set bmargin at screen TOP-4*DY
plot for[i=2:201] "I321_J321.dat" u 1:i lc rgb 'red' w l, for[i=2:21] "posterior/I321_J321.dat" u 1:i lc rgb 'blue' w l, "I321_J321.dat" u 1:plot lw 5 lc rgb 'black' w l

set xtics format ''
unset xlabel
set ytics ("" -0.15,"-0.1" -0.1,"" -0.05","0" 0,"" 0.05,"0.1" 0.1,"" 0.15)
set ylabel 'pK' offset -3 font ",32"
set tmargin at screen TOP-2*DY
set bmargin at screen TOP-3*DY
plot for[i=2:201] "I321_J2212.dat" u 1:i lc rgb 'red' w l, for[i=2:21] "posterior/I321_J2212.dat" u 1:i lc rgb 'blue' w l, "I321_J2212.dat" u 1:plot lw 5 lc rgb 'black' w l

set ylabel 'p~p{.4-}' enhanced offset -4 font ",32"
set ytics ("" -0.1,"0" 0,"0.1" 0.1,"0.2" 0.2,"0.3" 0.3,"0.4" 0.4)
set tmargin at screen TOP-1*DY
set bmargin at screen TOP-2*DY
plot for[i=2:201] "I2212_J2212.dat" u 1:i lc rgb 'red' w l, for[i=2:21] "posterior/I2212_J2212.dat" u 1:i lc rgb 'blue' w l, "I2212_J2212.dat" u 1:plot lw 5 lc rgb 'black' w l

set ylabel '{/Symbol p}{/Symbol p}' enhanced offset -4 font ",32"
set ytics ("-0.1" -0.1,"" 0,"0.1" 0.1,"" 0.2,"0.3" 0.3,"" 0.4, "0.5" 0.5)
set tmargin at screen TOP-0*DY
set bmargin at screen TOP-1*DY
set label "Prior" textcolor rgb "red" font ",32" at 1.1,0.55
set label "Posterior" textcolor rgb "blue" font ",32" at 1.1,0.4
set label "Full Model Calculation" textcolor rgb "black" font ",32" at 1.1,0.25
plot for[i=2:201] "I211_J211.dat" u 1:i lc rgb 'red' w l, for[i=2:21] "posterior/I211_J211.dat" u 1:i lc rgb 'blue' w l, "I211_J211.dat" u 1:plot lw 5 lc rgb 'black' w l

unset multiplot; set output