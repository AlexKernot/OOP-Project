cmake --build build
cd build;
ctest --output-on-failure;
#cd Testing/Temporary;
#cat LastTest.log