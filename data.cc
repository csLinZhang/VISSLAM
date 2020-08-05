For text data, we use boost for serilization. The following is the snippet for of how to read imu data.

void LoadData( ORB_SLAM2::IMUData::vector_t & gIMUData, string aIMUName){
    //Load IMU Data
    ifstream fIMUData(aIMUName);
    ostringstream sin;
    sin << fIMUData.rdbuf();
    string aIMUData = sin.str();
    
    //Recover IMU data from a string.
    std::stringstream is;
    is << aIMUData;
    boost::archive::text_iarchive ia(is);
    ia >> gIMUData;
}