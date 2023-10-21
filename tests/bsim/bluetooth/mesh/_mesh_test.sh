# Copyright 2021 Nordic Semiconductor
# SPDX-License-Identifier: Apache-2.0

source ${ZEPHYR_BASE}/tests/bsim/sh_common.source

EXECUTE_TIMEOUT=300

function Skip(){
  for i in "${SKIP[@]}" ; do
    if [ "$i" == "$1" ] ; then
      return 0
    fi
  done

  return 1
}

function RunTest(){
  verbosity_level=${verbosity_level:-2}
  extra_devs=${EXTRA_DEVS:-0}

  cd ${BSIM_OUT_PATH}/bin

  idx=0

  s_id=$1
  shift 1

<<<<<<< HEAD
  testids=()
  for testid in $@ ; do
    if [ "$testid" == "--" ]; then
=======
  declare -A testids
  testid=""
  testid_in_order=()

  for arg in $@ ; do
    if [ "$arg" == "--" ]; then
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
      shift 1
      break
    fi

<<<<<<< HEAD
    testids+=( $testid )
=======
    if [[ "$arg" == "-"* ]]; then
        testids["${testid}"]+="$arg "
    else
        testid=$arg
        testid_in_order+=($testid)
        testids["${testid}"]=""
    fi

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    shift 1
  done

  test_options=$@

<<<<<<< HEAD
  for testid in ${testids[@]} ; do
=======
  for testid in ${testid_in_order[@]}; do
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    if Skip $testid; then
      echo "Skipping $testid (device #$idx)"
      let idx=idx+1
      continue
    fi

    echo "Starting $testid as device #$idx"
    conf=${conf:-prj_conf}

    if [ ${overlay} ]; then
        exe_name=./bs_${BOARD}_tests_bsim_bluetooth_mesh_${conf}_${overlay}
    else
        exe_name=./bs_${BOARD}_tests_bsim_bluetooth_mesh_${conf}
    fi

    Execute \
      ${exe_name} \
      -v=${verbosity_level} -s=$s_id -d=$idx -sync_preboot -RealEncryption=1 \
<<<<<<< HEAD
      -testid=$testid ${test_options}
=======
      -testid=$testid ${testids["${testid}"]} ${test_options}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    let idx=idx+1
  done

  count=$(expr $idx + $extra_devs)

  echo "Starting phy with $count devices"

  Execute ./bs_2G4_phy_v1 -v=${verbosity_level} -s=$s_id -D=$count -argschannel -at=35

  wait_for_background_jobs
}
<<<<<<< HEAD
=======

function RunTestFlash(){
  s_id=$1
  ext_arg="${s_id} "
  idx=0
  shift 1

  for arg in $@ ; do
    if [ "$arg" == "--" ]; then
      ext_arg+=$@
      break
    fi

    ext_arg+="$arg "

    if [[ "$arg" != "-"* ]]; then
      ext_arg+="-flash=../results/${s_id}/${s_id}_${idx}.bin "
      let idx=idx+1
    fi

    shift 1
  done

  RunTest ${ext_arg}
}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
