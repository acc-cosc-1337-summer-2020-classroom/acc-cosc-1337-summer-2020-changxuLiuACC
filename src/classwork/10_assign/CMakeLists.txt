add_library(cw_10_library "employee.cpp" "employee.h" "engineer.h" "engineer.cpp" 
                          "sales_employee.h" "sales_employee.cpp")
add_executable(cw_10_exe "main.cpp" "employee.cpp" "engineer.cpp" "sales_employee.cpp")