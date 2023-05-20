cmake --build build --target 'jsonTest'
cd build;
ctest --output-on-failure;
#cd Testing/Temporary;
#cat LastTest.log