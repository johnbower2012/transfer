set macros;
set multiplot layout 4,2;
set key noautotitle; unset xlabel; unset ylabel;
set key font ",30";
set tics font ",30";

XRANGE="0.1:2.0";
PRIOR_OPTIONS="lc rgb 'blue' w lines"
POST_OPTIONS="lc rgb 'red' w lines"


XTICS="set xtics (0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8); set xlabel '{/Symbol D}{/Symbol h}' font ',30' at 1,-1200;"
NOXTICS="set xtics ('' 0.2,'' 0.4,'' 0.6,'' 0.8,'' 1.0,'' 1.2,'' 1.4,'' 1.6,'' 1.8); unset xlabel;"

YRANGE1="-5000:0"
YTICS1="set ytics (0, '' -1000 1,-2000,'' -3000 1,-4000); unset ylabel;"
NOYTICS1="set ytics ('' 0, '' -1000 1,'' -2000,'' -3000 1,'' -4000); unset ylabel;"
YRANGE2="0:1000"
YTICS2="set ytics (0,'' 200 1,400,'' 600 1,800); unset ylabel;"
NOYTICS2="set ytics ('' 0,'' 200 1, '' 400, '' 600 1, '' 800); unset ylabel;"
YRANGE3="0:500"
YTICS3="set ytics (0,'' 100 1,200,'' 300 1,400); unset ylabel;"
NOYTICS3="set ytics ('' 0,'' 100 1, '' 200, '' 300 1, '' 400); unset ylabel;"
YRANGE4="-1000:0"
YTICS4="set ytics (-800, '' -600 1, -400,'' -200 1,0); unset ylabel;"
NOYTICS4="set ytics ('' -800, '' -600 1, '' -400, '' -200 1, '' 0); unset ylabel;"


TMARGIN1="set tmargin at screen 0.90; set bmargin at screen 0.70;"
TMARGIN2="set tmargin at screen 0.70; set bmargin at screen 0.50;"
TMARGIN3="set tmargin at screen 0.50; set bmargin at screen 0.30;"
TMARGIN4="set tmargin at screen 0.30; set bmargin at screen 0.10;"
LMARGIN="set lmargin at screen 0.05; set rmargin at screen 0.5;"
RMARGIN="set lmargin at screen 0.50; set rmargin at screen 0.95;"

set title "Prior" font ",40";
set label "g_{uu}({/Symbol D}{/Symbol h})" enhanced font ",30" at 1.4,-1000;
@NOXTICS; @YTICS1;
@TMARGIN1; @LMARGIN;
plot [@XRANGE][@YRANGE1] for[i=2:21] "model_run00/prior/gab.dat" u 1:i @PRIOR_OPTIONS;
set title "Posterior" font ",40";
@NOXTICS; @NOYTICS1;
@TMARGIN1; @RMARGIN;
plot [@XRANGE][@YRANGE1] for[i=2:21] "model_run00/posterior/gab.dat" u 1:i @POST_OPTIONS;
unset label;
unset title;

set label "g_{ud}({/Symbol D}{/Symbol h})" enhanced font ",30" at 1.4,800;
@NOXTICS; @YTICS2;
@TMARGIN2; @LMARGIN;
plot [@XRANGE][@YRANGE2] for[i=22:41] "model_run00/prior/gab.dat" u 1:i @PRIOR_OPTIONS;
@NOXTICS; @NOYTICS2; 
@TMARGIN2; @RMARGIN;
unset label;
set label "g_{ud}({/Symbol D}{/Symbol h})" enhanced font ",30" at 1.4,800;
plot [@XRANGE][@YRANGE2] for[i=22:41] "model_run00/posterior/gab.dat" u 1:i @POST_OPTIONS;
unset label;p

set label  "g_{us}({/Symbol D}{/Symbol h})" enhanced font ",30" at 1.4,400;
@TMARGIN3; @LMARGIN;
@NOXTICS; @YTICS3;
plot [@XRANGE][@YRANGE3] for[i=42:61] "model_run00/prior/gab.dat" u 1:i @PRIOR_OPTIONS;
@NOXTICS; @NOYTICS3;
@TMARGIN3; @RMARGIN;
plot [@XRANGE][@YRANGE3] for[i=42:61] "model_run00/posterior/gab.dat" u 1:i @POST_OPTIONS;
unset label;

set label  "g_{ss}({/Symbol D}{/Symbol h})" enhanced font ",30" at 1.4,-400;
@XTICS; @YTICS4;
@TMARGIN4; @LMARGIN;
plot [@XRANGE][@YRANGE4] for[i=62:81] "model_run00/prior/gab.dat" u 1:i @PRIOR_OPTIONS;
@XTICS; @NOYTICS4;
@TMARGIN4; @RMARGIN;
plot [@XRANGE][@YRANGE4] for[i=62:81] "model_run00/posterior/gab.dat" u 1:i @POST_OPTIONS;
unset label;
