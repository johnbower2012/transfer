clear
orientation portrait
device\colour postscript
!! cursor -2 is for centering, -1 is for left justify, -3 for right just.
set cursor -2

read ../results/results3d_steffen.dat kt lambda_steffen Rout_steffen Routlab_steffen Rside_steffen Rlong_steffen ratio_steffen

read ../results/results3d_stupid.dat kt lambda_stupid Rout_stupid Routlab_stupid Rside_stupid Rlong_stupid ratio_stupid

read ../results/results3d_fixed_tau0.dat kt lambda_fixedtau0 Rout_fixedtau0 Routlab_fixedtau0 Rside_fixedtau0 Rlong_fixedtau0 ratio_fixedtau0

read ../results/results3d_fixed_tau0eos.dat kt lambda_fixedtau0eos Rout_fixedtau0eos Routlab_fixedtau0eos Rside_fixedtau0eos Rlong_fixedtau0eos ratio_fixedtau0eos

read ../results/results3d_default.dat kt lambda_default Rout_default Routlab_default Rside_default Rlong_default ratio_default

read ../results/results3d_bowlersinyukov_default_fullwf.dat kt lambda_default_fullwf Rout_default_fullwf Routlab_default_fullwf Rside_default_fullwf Rlong_default_fullwf ratio_default_fullwf

read ../results/star.dat kt_star lambda Routlab_star Rside_star Rlong_star
ratio_star=Routlab_star/Rside_star

!__________________________________________
! LOWER PANEL
!___________________________________________
set xleadz 1.0
set yleadz 1.0
set xnumsz .6
set ynumsz .6
set xticl -.5
set xtics -.25
set yticl -.5
set ytics -.25
set xlabsz 1.0
set ylabsz 1.0
set lintyp 1.0
set linthk 6.0
set charsz 0.4
!set xlog 10
!set ylog 10
!!ylabel "P(n)"
!!xlabel "n"
!___________________________________________
!These are the dimensions of the borders
xxll=4.0
xxuu=16
yyll=3.5
yyuu=9
!___________________________________________
!delxlabel and delylabel are the offsets of the label.
delxlabel=2.5
delylabel=2.5
set xlaxis xxll
set xuaxis xxuu
set ylaxis yyll
set yuaxis yyuu
!___________________________________________
color 1

! y-axis label
set cursor -2
ytext=(yyll+yyuu)/2.0
xtext=xxll-delylabel
set xloc xtext
set yloc ytext
set txtang 90
set txthit 0.7
text `R<_>long<^>'

! x-axis label
xtext=(xxuu+xxll)/2.0
ytext=yyll-delxlabel
set xloc xtext
set yloc ytext
set txtang 0
set txthit .7
text `k<_>t<^> (MeV/c)'

!autoscale
!usage: scales xmin,xmax,ymin,ymax
scales 0 550 4 15.999

! These 8 par.s set the locations of tick marks
set xvmin 0.0
set xvmax 600
set nlxinc 6
set nsxinc 2

set yvmin 4.0
set yvmax 16.0
set nlyinc 3
set nsyinc 2

graph\axesonly

color 1
set pchar 12
!graph\noaxes kt Rlong_steffen

color green
set pchar 12
!graph\noaxes kt Rlong_stupid

color blue
set pchar 10
!graph\noaxes kt Rlong_fixedtau0

color cyan
set pchar 1
!graph\noaxes kt Rlong_fixedtau0eos

color blue
set pchar 10
graph\noaxes kt Rlong_default

color 1
set pchar 12
graph\noaxes kt Rlong_default_fullwf

color red
set pchar -15
graph\noaxes kt_star Rlong_star

xtext=xxuu-1
set cursor -3
ytext=yyll+1.4
set xloc xtext
set yloc ytext
set txtang 0
set txthit 0.6
color green
!text `<eta>=2<eta,_>DSS<^> , <zeta><_>max<^>=2<eta,_>DSS<^>'

!-----------------------------------------------
!__________________________________________
! LOWER MIDDLE PANEL
!___________________________________________
set xnumsz 0.0
yyll=9
yyuu=14.5
!___________________________________________
!delxlabel and delylabel are the offsets of the label.
delxlabel=2.8
delylabel=2.5
set xlaxis xxll
set xuaxis xxuu
set ylaxis yyll
set yuaxis yyuu
!___________________________________________
color 1

! y-axis label
set cursor -2
ytext=(yyll+yyuu)/2.0
xtext=xxll-delylabel
set xloc xtext
set yloc ytext
set txtang 90
set txthit 0.7
text `R<_>side<^>'

!autoscale
!usage: scales xmin,xmax,ymin,ymax
scales 0 550 3 7.9999

! These 8 par.s set the locations of tick marks

set yvmin 4.0
set yvmax 12.0
set nlyinc 4
set nsyinc 2

graph\axesonly

color 1
set pchar 12
!graph\noaxes kt Rside_steffen

color green
set pchar 12
!graph\noaxes kt Rside_stupid

color blue
set pchar 10
!graph\noaxes kt Rside_fixedtau0

color cyan
set pchar 1
!graph\noaxes kt Rside_fixedtau0eos

color blue
set pchar 10
graph\noaxes kt Rside_default

color 1
set pchar 12
graph\noaxes kt Rside_default_fullwf

color red
set pchar -15
graph\noaxes kt_star Rside_star


!__________________________________________
! UPPER MIDDLE PANEL
!___________________________________________
set xnumsz 0.0
yyll=14.5
yyuu=20
!___________________________________________
!delxlabel and delylabel are the offsets of the label.
delxlabel=2.8
delylabel=2.5
set xlaxis xxll
set xuaxis xxuu
set ylaxis yyll
set yuaxis yyuu
!___________________________________________
color 1

! y-axis label
set cursor -2
ytext=(yyll+yyuu)/2.0
xtext=xxll-delylabel
set xloc xtext
set yloc ytext
set txtang 90
set txthit 0.7
text `R<_>out<^>'

!autoscale
!usage: scales xmin,xmax,ymin,ymax
scales 0 550 4 9.0

! These 8 par.s set the locations of tick marks

set yvmin 4.0
set yvmax 12.0
set nlyinc 4
set nsyinc 2

graph\axesonly

color 1
set pchar 12
!graph\noaxes kt Routlab_steffen

color green
set pchar 12
!graph\noaxes kt Routlab_stupid

color blue
set pchar 10
!graph\noaxes kt Routlab_fixedtau0

color cyan
set pchar 1
!graph\noaxes kt Routlab_fixedtau0eos

color blue
set pchar 10
graph\noaxes kt Routlab_default

color 1
set pchar 12
graph\noaxes kt Routlab_default_fullwf

color red
set pchar -15
graph\noaxes kt_star Routlab_star


!-----------------------------------------------
!__________________________________________
! UPPER PANEL
!___________________________________________
set xnumsz 0.0
yyll=20
yyuu=24
!___________________________________________
!delxlabel and delylabel are the offsets of the label.
delxlabel=2.8
delylabel=2.5
set xlaxis xxll
set xuaxis xxuu
set ylaxis yyll
set yuaxis yyuu
!___________________________________________
color 1

! y-axis label
set cursor -2
ytext=(yyll+yyuu)/2.0
xtext=xxll-delylabel
set xloc xtext
set yloc ytext
set txtang 90
set txthit 0.7
text `R<_>out<^>/R<_>side<^>'

!autoscale
!usage: scales xmin,xmax,ymin,ymax
scales 0 550 0.9 1.2

! These 8 par.s set the locations of tick marks

set yvmin 0.8
set yvmax 1.6
set nlyinc 4
set nsyinc 2

graph\axesonly

color 1
set pchar 12
!graph\noaxes kt ratio_steffen

color green
set pchar 12
!graph\noaxes kt ratio_stupid

color blue
set pchar 10
!graph\noaxes kt ratio_fixedtau0

color cyan
set pchar 1
!graph\noaxes kt ratio_fixedtau0eos

color blue
set pchar 10
graph\noaxes kt ratio_default

color 1
set pchar 12
graph\noaxes kt ratio_default_fullwf

color red
set pchar -15
graph\noaxes kt_star ratio_star


!-----------------------------------------------
hardcopy s Rosl_bowler.eps
