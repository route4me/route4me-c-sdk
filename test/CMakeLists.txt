
ADD_EXECUTABLE(GetVehicles GetVehicles.c)
TARGET_LINK_LIBRARIES(GetVehicles route4me)

ADD_EXECUTABLE(RouteStatus RouteStatus.c)
TARGET_LINK_LIBRARIES(RouteStatus route4me)

ADD_EXECUTABLE(GetRoutes GetRoutes.c)
TARGET_LINK_LIBRARIES(GetRoutes route4me)

ADD_EXECUTABLE(GetRouteById GetRouteById.c)
TARGET_LINK_LIBRARIES(GetRouteById route4me)

ADD_EXECUTABLE(GetRouteByPath GetRouteByPath.c)
TARGET_LINK_LIBRARIES(GetRouteByPath route4me)

ADD_EXECUTABLE(GetRouteDirections GetRouteDirections.c)
TARGET_LINK_LIBRARIES(GetRouteDirections route4me)

ADD_EXECUTABLE(GetRouteQuery GetRouteQuery.c)
TARGET_LINK_LIBRARIES(GetRouteQuery route4me)

ADD_EXECUTABLE(UpdateRoute UpdateRoute.c)
TARGET_LINK_LIBRARIES(UpdateRoute route4me)

ADD_EXECUTABLE(DuplicateRoute DuplicateRoute.c)
TARGET_LINK_LIBRARIES(DuplicateRoute route4me)

ADD_EXECUTABLE(ShareRoute ShareRoute.c)
TARGET_LINK_LIBRARIES(ShareRoute route4me)

ADD_EXECUTABLE(DeleteRoute DeleteRoute.c)
TARGET_LINK_LIBRARIES(DeleteRoute route4me)

ADD_EXECUTABLE(GetAddress GetAddress.c)
TARGET_LINK_LIBRARIES(GetAddress route4me)

ADD_EXECUTABLE(AddRouteNotes AddRouteNotes.c)
TARGET_LINK_LIBRARIES(AddRouteNotes route4me)

ADD_EXECUTABLE(GetRouteNotes GetRouteNotes.c)
TARGET_LINK_LIBRARIES(GetRouteNotes route4me)

ADD_EXECUTABLE(SetGps SetGps.c)
TARGET_LINK_LIBRARIES(SetGps route4me)

ADD_EXECUTABLE(AddOptimization AddOptimization.c)
TARGET_LINK_LIBRARIES(AddOptimization route4me)

ADD_EXECUTABLE(Reoptimization Reoptimization.c)
TARGET_LINK_LIBRARIES(Reoptimization route4me)

ADD_EXECUTABLE(GetOptimization GetOptimization.c)
TARGET_LINK_LIBRARIES(GetOptimization route4me)

ADD_EXECUTABLE(GetOptimizations GetOptimizations.c)
TARGET_LINK_LIBRARIES(GetOptimizations route4me)

ADD_EXECUTABLE(RemoveOptimization RemoveOptimization.c)
TARGET_LINK_LIBRARIES(RemoveOptimization route4me)

ADD_EXECUTABLE(AddAddressToOptimization AddAddressToOptimization.c)
TARGET_LINK_LIBRARIES(AddAddressToOptimization route4me)

ADD_EXECUTABLE(GetAllActivities GetAllActivities.c)
TARGET_LINK_LIBRARIES(GetAllActivities route4me)

ADD_EXECUTABLE(LogActivity LogActivity.c)
TARGET_LINK_LIBRARIES(LogActivity route4me)

ADD_EXECUTABLE(GetTeamActivities GetTeamActivities.c)
TARGET_LINK_LIBRARIES(GetTeamActivities route4me)

ADD_EXECUTABLE(GetActivityByType GetActivityByType.c)
TARGET_LINK_LIBRARIES(GetActivityByType route4me)

ADD_EXECUTABLE(GetAllUsers GetAllUsers.c)
TARGET_LINK_LIBRARIES(GetAllUsers route4me)

ADD_EXECUTABLE(AuthenticateUser AuthenticateUser.c)
TARGET_LINK_LIBRARIES(AuthenticateUser route4me)

ADD_EXECUTABLE(AssetTracking AssetTracking.c)
TARGET_LINK_LIBRARIES(AssetTracking route4me)

ADD_EXECUTABLE(GetStreetAddress GetStreetAddress.c)
TARGET_LINK_LIBRARIES(GetStreetAddress route4me)

ADD_EXECUTABLE(GetAllStreets GetAllStreets.c)
TARGET_LINK_LIBRARIES(GetAllStreets route4me)

ADD_EXECUTABLE(BatchGeocoder BatchGeocoder.c)
TARGET_LINK_LIBRARIES(BatchGeocoder route4me)

ADD_EXECUTABLE(ReverseGeocoder ReverseGeocoder.c)
TARGET_LINK_LIBRARIES(ReverseGeocoder route4me)

ADD_EXECUTABLE(AddAvoidanceZone AddAvoidanceZone.c)
TARGET_LINK_LIBRARIES(AddAvoidanceZone route4me)

ADD_EXECUTABLE(GetAvoidanceZone GetAvoidanceZone.c)
TARGET_LINK_LIBRARIES(GetAvoidanceZone route4me)

ADD_EXECUTABLE(GetOrder GetOrder.c)
TARGET_LINK_LIBRARIES(GetOrder route4me)

ADD_EXECUTABLE(GetAllOrders GetAllOrders.c)
TARGET_LINK_LIBRARIES(GetAllOrders route4me)

ADD_EXECUTABLE(OptimizeAndReoptimize OptimizeAndReoptimize.c)
TARGET_LINK_LIBRARIES(OptimizeAndReoptimize route4me)

ADD_EXECUTABLE(AddConfig AddConfig.c)
TARGET_LINK_LIBRARIES(AddConfig route4me)

ADD_EXECUTABLE(GetConfig GetConfig.c)
TARGET_LINK_LIBRARIES(GetConfig route4me)

ADD_EXECUTABLE(PreviewFile PreviewFile.c)
TARGET_LINK_LIBRARIES(PreviewFile route4me)

ADD_EXECUTABLE(UploadFile UploadFile.c)
TARGET_LINK_LIBRARIES(UploadFile route4me)

ADD_EXECUTABLE(ValidateSession ValidateSession.c)
TARGET_LINK_LIBRARIES(ValidateSession route4me)

ADD_EXECUTABLE(SingleDriverRoundTrip SingleDriverRoundTrip.c)
TARGET_LINK_LIBRARIES(SingleDriverRoundTrip route4me)

ADD_EXECUTABLE(MultipleDepotMultipleDriverTimeWindow MultipleDepotMultipleDriverTimeWindow.c)
TARGET_LINK_LIBRARIES(MultipleDepotMultipleDriverTimeWindow route4me)

ADD_EXECUTABLE(SingleDepotMultipleDriver SingleDepotMultipleDriver.c)
TARGET_LINK_LIBRARIES(SingleDepotMultipleDriver route4me)

ADD_EXECUTABLE(AddTerritory AddTerritory.c)
TARGET_LINK_LIBRARIES(AddTerritory route4me)

ADD_EXECUTABLE(GetTerritory GetTerritory.c)
TARGET_LINK_LIBRARIES(GetTerritory route4me)

ADD_EXECUTABLE(RemoveTerritory RemoveTerritory.c)
TARGET_LINK_LIBRARIES(RemoveTerritory route4me)

ADD_EXECUTABLE(GetContacts GetContacts.c)
TARGET_LINK_LIBRARIES(GetContacts route4me)

ADD_EXECUTABLE(RemoveAddressFromOptimization RemoveAddressFromOptimization.c)
TARGET_LINK_LIBRARIES(RemoveAddressFromOptimization route4me)

