/*
  Copyright (C) 2015-2019 The Android Open Source Project
  
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  
       http://www.apache.org/licenses/LICENSE-2.0
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  
  
  This contains the module build definitions for the hardware-specific
  components for this device.
  
  As much as possible, those components should be built unconditionally,
  with device-specific names to avoid collisions, to avoid device-specific
  bitrot and build breakages. Building a component unconditionally does
  *not* include it on all devices, so it is safe even with hardware-specific
  components.
*/

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "log.h"

namespace android {
namespace init {

void vendor_load_properties() {
    std::string boardID = android::base::GetProperty("ro.boot.boardID", "");

    if (boardID == "0") {
        /* If ro.boot.boardID=0, set as kate */
        property_set("ro.product.brand", "Xiaomi");
        property_set("ro.product.manufacturer", "Xiaomi");
        property_set("ro.product.model", "Redmi Note 3");
        property_set("ro.product.device", "kate");
        property_set("ro.product.name", "kate");
        property_set("ro.build.fingerprint", "Xiaomi/kate/kate:6.0.1/MMB29M/V10.2.1.0.MHRMIXM:user/release-keys");
        property_set("ro.build.description", "kate-user 6.0.1 MMB29M V10.2.1.0.MHRMIXM release-keys");
    }

    else {
        /* Otherwise, set as kenzo */
        property_set("ro.product.brand", "Xiaomi");
        property_set("ro.product.manufacturer", "Xiaomi");
        property_set("ro.product.model", "Redmi Note 3");
        property_set("ro.product.device", "kenzo");
        property_set("ro.product.name", "kenzo");
        property_set("ro.build.fingerprint", "Xiaomi/kenzo/kenzo:6.0.1/MMB29M/V10.2.1.0.MHOMIXM:user/release-keys");
        property_set("ro.build.description", "kenzo-user 6.0.1 MMB29M V10.2.1.0.MHOMIXM release-keys");
    }
}

}  // namespace init
}  // namespace android
