/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/powerstats/BnPowerStats.h>

namespace aidl {
namespace android {
namespace hardware {
namespace powerstats {

class PowerStats : public BnPowerStats {
  public:
    PowerStats() = default;
    // Methods from aidl::android::hardware::powerstats::IPowerStats
    ndk::ScopedAStatus getPowerEntityInfo(std::vector<PowerEntityInfo>* _aidl_return) override;
    ndk::ScopedAStatus getPowerEntityStateResidency(
            const std::vector<int32_t>& in_powerEntityIds,
            std::vector<StateResidencyResult>* _aidl_return) override;
    ndk::ScopedAStatus getEnergyConsumerInfo(std::vector<EnergyConsumerId>* _aidl_return) override;
    ndk::ScopedAStatus getEnergyConsumed(const std::vector<EnergyConsumerId>& in_energyConsumerIds,
                                         std::vector<EnergyConsumerResult>* _aidl_return) override;
    ndk::ScopedAStatus getEnergyMeterInfo(std::vector<ChannelInfo>* _aidl_return) override;
    ndk::ScopedAStatus readEnergyMeters(const std::vector<int32_t>& in_channelIds,
                                        std::vector<EnergyMeasurement>* _aidl_return) override;
};

}  // namespace powerstats
}  // namespace hardware
}  // namespace android
}  // namespace aidl
