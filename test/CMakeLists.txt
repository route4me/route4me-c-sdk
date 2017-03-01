ENABLE_TESTING()

ADD_EXECUTABLE(StringUtilsTest StringUtilsTest)
TARGET_LINK_LIBRARIES(StringUtilsTest route4me)
TARGET_LINK_LIBRARIES(StringUtilsTest -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(StringUtilsTest StringUtilsTest)

ADD_EXECUTABLE(ActivitiesTest ActivitiesTest)
TARGET_LINK_LIBRARIES(ActivitiesTest route4me)
TARGET_LINK_LIBRARIES(ActivitiesTest -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(ActivitiesTest ActivitiesTest)

ADD_EXECUTABLE(AddressBookTest AddressBookTest)
TARGET_LINK_LIBRARIES(AddressBookTest route4me)
TARGET_LINK_LIBRARIES(AddressBookTest -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(AddressBookTest AddressBookTest)

ADD_EXECUTABLE(AvoidanceZonesTest AvoidanceZonesTest)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest route4me)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(AvoidanceZonesTest AvoidanceZonesTest)
