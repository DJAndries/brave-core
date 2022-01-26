/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_H_

#include <memory>
#include <string>

#include "base/containers/flat_map.h"
#include "bat/ads/internal/federated/federated_logs_entry_types.h"

namespace base {
class Value;
}

namespace ads {

class FederatedLogsEntry;

class FederatedLogs final {
 public:
  FederatedLogs();
  FederatedLogs(const FederatedLogs&) = delete;
  FederatedLogs& operator=(const FederatedLogs&) = delete;
  ~FederatedLogs();

  static FederatedLogs* Get();

  void SetFederatedLogsEntry(std::unique_ptr<FederatedLogsEntry> entry);
  std::string GetFederatedLogs() const;

 private:
  base::Value CollectFederatedLogs() const;

  base::flat_map<FederatedLogsEntryType, std::unique_ptr<FederatedLogsEntry>>
      federated_logs_entries_;
};

}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_H_
