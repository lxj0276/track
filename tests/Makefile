test_engine.o: test_engine.cpp test_engine.hpp
	g++ -g -std=c++11 -c test_engine.cpp `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs` -I../RTree

test: test.cpp test_engine.o
	g++ -g -std=c++11 test_engine.o test.cpp -o test -lboost_system -lboost_filesystem

pugixml.o: pugixml.cpp pugixml.hpp
	g++ -g -std=c++11 -c pugixml.cpp

detect_table.o: ../detect_table.cpp
	g++ -g -std=c++11 -c -I../ ../detect_table.cpp

detect_cell.o: ../detect_cell.cpp
	g++ -g -std=c++11 -c -I../ ../detect_cell.cpp

textbox_ocr.o: ../textbox_ocr.cpp
	g++ -g -std=c++11 -c -I../ ../textbox_ocr.cpp


tableDetectionTest: tableDetectionTest.cpp pugixml.o test_engine.o detect_table.o
	g++ -g -std=c++11 pugixml.o test_engine.o detect_table.o tableDetectionTest.cpp -o tableDetectionTest -lboost_system -lboost_filesystem `pkg-config --cflags --libs opencv` `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs` -I../ -I../RTree

cellDetectionTest: cellDetectionTest.cpp pugixml.o test_engine.o detect_cell.o
	g++ -g -std=c++11 pugixml.o test_engine.o detect_cell.o cellDetectionTest.cpp -o cellDetectionTest -lboost_system -lboost_filesystem `pkg-config --cflags --libs opencv` `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs` -I../ -I../RTree

ocrTest: ocrTest.cpp test_engine.o textbox_ocr.o
	g++ -g -std=c++11 pugixml.o test_engine.o textbox_ocr.o ocrTest.cpp -o ocrTest -lboost_system -lboost_filesystem `pkg-config --cflags --libs opencv` `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs` -I../ -I../RTree -lleptonica -ltesseract

translate: translate.cpp
	g++ -g -std=c++11 translate.cpp -o translate `Magick++-config --cxxflags --cppflags` `Magick++-config --ldflags --libs`
