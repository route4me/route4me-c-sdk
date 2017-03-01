ENABLE_TESTING()

ADD_EXECUTABLE(StringUtilsTest StringUtilsTest.c)
TARGET_LINK_LIBRARIES(StringUtilsTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(StringUtilsTest StringUtilsTest)

ADD_EXECUTABLE(ActivitiesTest ActivitiesTest.c)
TARGET_LINK_LIBRARIES(ActivitiesTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(ActivitiesTest ActivitiesTest)

ADD_EXECUTABLE(AddressBookTest AddressBookTest.c)
TARGET_LINK_LIBRARIES(AddressBookTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(AddressBookTest AddressBookTest)

ADD_EXECUTABLE(AvoidanceZonesTest AvoidanceZonesTest.c)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(AvoidanceZonesTest AvoidanceZonesTest)

ADD_EXECUTABLE(RouteTest RouteTest.c)
TARGET_LINK_LIBRARIES(RouteTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(RouteTest RouteTest)

ADD_EXECUTABLE(StreetsTest StreetsTest.c)
TARGET_LINK_LIBRARIES(StreetsTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(StreetsTest StreetsTest)

ADD_EXECUTABLE(ConfigTest ConfigTest.c)
TARGET_LINK_LIBRARIES(ConfigTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(ConfigTest ConfigTest)

ADD_EXECUTABLE(GeocoderTest GeocoderTest.c)
TARGET_LINK_LIBRARIES(GeocoderTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(GeocoderTest GeocoderTest)

ADD_EXECUTABLE(GPSTest GPSTest.c)
TARGET_LINK_LIBRARIES(GPSTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(GPSTest GPSTest)

ADD_EXECUTABLE(NotesTest NotesTest.c)
TARGET_LINK_LIBRARIES(NotesTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(NotesTest NotesTest)

ADD_EXECUTABLE(OptimizationTest OptimizationTest.c)
TARGET_LINK_LIBRARIES(OptimizationTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(OptimizationTest OptimizationTest)

ADD_EXECUTABLE(OrdersTest OrdersTest.c)
TARGET_LINK_LIBRARIES(OrdersTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(OrdersTest OrdersTest)

ADD_EXECUTABLE(SessionTest SessionTest.c)
TARGET_LINK_LIBRARIES(SessionTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(SessionTest SessionTest)

ADD_EXECUTABLE(TerritoriesTest TerritoriesTest.c)
TARGET_LINK_LIBRARIES(TerritoriesTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(TerritoriesTest TerritoriesTest)

ADD_EXECUTABLE(TrackingTest TrackingTest.c)
TARGET_LINK_LIBRARIES(TrackingTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(TrackingTest TrackingTest)

ADD_EXECUTABLE(UsersTest UsersTest.c)
TARGET_LINK_LIBRARIES(UsersTest route4me -L${CMOCKA_LIBRARY} -lcmocka)
ADD_TEST(UsersTest UsersTest)
