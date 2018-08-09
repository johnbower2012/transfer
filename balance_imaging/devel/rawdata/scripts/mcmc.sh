MCMC_RUNS=$3
DEST_FOLDER='calculations/mcmc/'

for((i=$1;i<$2;i++))
do
    fn=` printf "model_run%02d/" $i `
    echo "Running for directory ${fn} ..."
    cp -v calculations/moments/${fn}moments_plot.dat ${DEST_FOLDER}${fn}
    cp -v calculations/moments/${fn}moments_exp_z.dat ${DEST_FOLDER}${fn}
    cp -v calculations/fitting/${fn}beta.dat ${DEST_FOLDER}${fn}
    cp -v calculations/emulator/${fn}hyperparameters.dat ${DEST_FOLDER}${fn}

    echo "./${DEST_FOLDER}mcmc.x ${DEST_FOLDER}${fn}moments_plot.dat ${DEST_FOLDER}${fn}moments_exp_z.dat ${DEST_FOLDER}${fn}beta.dat ${DEST_FOLDER}${fn}hyperparamters.dat $MCMC_RUNS ${DEST_FOLDER}${fn}mcmctrace.csv"
    ./${DEST_FOLDER}mcmc.x ${DEST_FOLDER}${fn}moments_plot.dat ${DEST_FOLDER}${fn}moments_exp_z.dat ${DEST_FOLDER}${fn}beta.dat ${DEST_FOLDER}${fn}hyperparameters.dat $MCMC_RUNS ${DEST_FOLDER}${fn}mcmctrace.csv
done