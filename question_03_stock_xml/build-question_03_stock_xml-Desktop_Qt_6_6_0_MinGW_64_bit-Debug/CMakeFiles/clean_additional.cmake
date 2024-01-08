# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\question_03_stock_xml_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\question_03_stock_xml_autogen.dir\\ParseCache.txt"
  "question_03_stock_xml_autogen"
  )
endif()
