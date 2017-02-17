
SET(CROUTE4ME_SOURCE
  route4me.c
  json_deserialize.c
  string_utils.c
  ${JSON_C_DIR}/json.h
)

ADD_LIBRARY(route4me STATIC ${CROUTE4ME_SOURCE})
TARGET_LINK_LIBRARIES(route4me ${CURL_LIBRARY})
TARGET_LINK_LIBRARIES(route4me ${JSON_C_LIBRARY}/libjson-c.so)

