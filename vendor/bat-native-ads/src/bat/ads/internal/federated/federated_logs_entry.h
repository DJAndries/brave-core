/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_ENTRY_H_
#define BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_ENTRY_H_

#include <string>

#include "bat/ads/internal/federated/federated_logs_entry_types.h"

namespace ads {

class FederatedLogsEntry {
 public:
  FederatedLogsEntry();
  virtual ~FederatedLogsEntry();

  virtual FederatedLogsEntryType GetEntryType() const = 0;
  virtual std::string GetKey() const = 0;
  // TODO(Moritz Haller): Make base::Value to allow arbitrary return types?
  virtual std::string GetValue() const = 0;
};

}  // namespace ads

#endif  // BRAVE_VENDOR_BAT_NATIVE_ADS_SRC_BAT_ADS_INTERNAL_FEDERATED_FEDERATED_LOGS_ENTRY_H_
