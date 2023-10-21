# The coverage linker flag is specific for clang.
<<<<<<< HEAD
if (NOT CONFIG_COVERAGE_GCOV)
  set_property(TARGET linker PROPERTY coverage --coverage)
=======
if (CONFIG_COVERAGE_NATIVE_GCOV)
  set_property(TARGET linker PROPERTY coverage --coverage)
elseif(CONFIG_COVERAGE_NATIVE_SOURCE)
  set_property(TARGET linker PROPERTY coverage -fprofile-instr-generate -fcoverage-mapping)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
endif()

# Extra warnings options for twister run
set_property(TARGET linker PROPERTY ld_extra_warning_options -Wl,--fatal-warnings)
