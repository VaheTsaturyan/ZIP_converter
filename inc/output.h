#pragma once 
#include "include.h"
#include "myLess.h"

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>

namespace my{

class ioClass{
public:
    void getQue(priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> ioQue);
    void getIoString(string& ioString);
    void getFormat(string& format);
    void getLasRedundantBits(short lasRedundantBits);

    priority_queue<pair<char, int>, vector<pair<char, int>> , myLess<pair<char, int>>> setQue();
    string& setIoString();
    string& setFormat();
    short& setLasRedundantBits();

private:
    vector<pair<char, int>> ioVec_;
    string ioString_; 
    string format_;
    short lasRedundantBits_;
//    friend std::istream& operator>>(std::istream& is, ioClass& obj);
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(ioVec_);
        ar & BOOST_SERIALIZATION_NVP(ioString_);
        ar & BOOST_SERIALIZATION_NVP(format_);
        ar & BOOST_SERIALIZATION_NVP(lasRedundantBits_);
    }

};

inline const char* ZIP_FORMAT = "zbv";

} // namespace my
