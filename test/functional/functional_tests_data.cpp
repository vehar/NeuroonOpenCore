#include "functional_tests_data.h"

dlib::matrix<double> read_signal_from_file(const std::string &filename) {
	dlib::matrix<double> data;
	std::ifstream in(filename);
	if (in.good()) {
		in >> data;
		if (in.fail()) {
			std::stringstream s;
			s << "Could not read data from: " << filename;
			throw std::logic_error(s.str());
		}
	} else {
		std::cout << "Stream not good...\n";
		in.close();
		std::stringstream s;
		s << "Could not read data from: " << filename;
		throw std::logic_error(s.str());
	}

	dlib::matrix<double> signal = dlib::colm(data, 1);
	return signal;
}

dlib::matrix<double> get_eeg_data(std::string filename) {
	if (filename.empty()) {
		filename = "../../../test/test_data/TG_190616_EEG.csv";
	}
	return read_signal_from_file(filename);
}

dlib::matrix<double> get_ir_data(std::string filename) {
	if (filename.empty()) {
		filename = "../../../test/test_data/TG_190616_IR.csv";
	}
	return read_signal_from_file(filename);
}

dlib::matrix<double> get_python_features() {
	std::string TEST_FEATURES_FILENAME("../../../test/test_data/LL_200516_python_features.csv");
	dlib::matrix<double> features = load_matrix(TEST_FEATURES_FILENAME);
	return features;
}

dlib::matrix<double> get_online_python_features() {
	std::string TEST_FEATURES_FILENAME("../../../test/test_data/TG_190616_online_features.csv");
	dlib::matrix<double> features = load_matrix(TEST_FEATURES_FILENAME);
	return features;
}

