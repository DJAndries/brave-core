/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_LOG_ENTRIES_TABS_OPENED_FEDERATED_LOGS_ENTRY_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_LOG_ENTRIES_TABS_OPENED_FEDERATED_LOGS_ENTRY_H_

#include <string>

#include "bat/ads/internal/federated/federated_logs_entry.h"

namespace ads {

class TabsOpenedFederatedLogsEntry final : public FederatedLogsEntry {
 public:
  TabsOpenedFederatedLogsEntry();
  TabsOpenedFederatedLogsEntry(
      const TabsOpenedFederatedLogsEntry&) = delete;
  TabsOpenedFederatedLogsEntry& operator=(
      const TabsOpenedFederatedLogsEntry&) = delete;
  ~TabsOpenedFederatedLogsEntry() override;

  // FederatedLogsEntry
  FederatedLogsEntryType GetEntryType() const override;
  std::string GetKey() const override;
  std::string GetValue() const override;
};

}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_LOG_ENTRIES_TABS_OPENED_FEDERATED_LOGS_ENTRY_H_
