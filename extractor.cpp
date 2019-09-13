#include <bits/stdc++.h>
#include <openenclave/host.h>

using namespace std;

// Simple test program to get the embedded SHA256 sum from an
// oe quote in a file.

int main(int argc, char** argv) {
	if(argc < 2) {
		cerr << argv[0] << " <quote file>" << endl;
		return 1;
	}

	// read in the quote file
	string s = argv[1];
	ifstream fin(s, ios::ate);
	auto sz = fin.tellg();
	fin.seekg(ios::beg);
	vector<uint8_t> buf(sz);
	fin.read((char*)&buf[0], sz);

	// use openenclave to verify the report
	oe_report_t report;
	assert(oe_verify_report(0, &buf[0], buf.size(), &report) == OE_OK);

	uint8_t* data = report.report_data;
	size_t data_len = report.report_data_size;

	// print out the hash
	for(int i = 0; i < data_len; i++) {
		cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]);
	} cout << endl;

	return 0;
}
