/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/federated/log_entries/tabs_opened_federated_logs_entry.h"

#include <cstdint>

#include "bat/ads/ads_client.h"
#include "bat/ads/internal/federated/federated_logs_util.h"
#include "bat/ads/internal/ads_client_helper.h"
#include "bat/ads/internal/user_activity/user_activity.h"
#include "bat/ads/pref_names.h"

namespace ads {

namespace {

int64_t ComputeTabsOpened(const UserActivityEventList& events) {
  int64_t count = 0;
  for (const auto& event : events) {
    if (event.type  == UserActivityEventType::kOpenedNewTab) {
      count++;
    }
  }

  return count;
}

}  // namespace

TabsOpenedFederatedLogsEntry::TabsOpenedFederatedLogsEntry() = default;

TabsOpenedFederatedLogsEntry::~TabsOpenedFederatedLogsEntry() = default;

FederatedLogsEntryType TabsOpenedFederatedLogsEntry::GetEntryType() const {
  return FederatedLogsEntryType::kTabsOpened;
}

std::string TabsOpenedFederatedLogsEntry::GetKey() const {
  return "Tabs opened";
}

std::string TabsOpenedFederatedLogsEntry::GetValue() const {
  // TODO(Moritz Haller): every feature computes on a new copy of history_
  const UserActivityEventList events =
      UserActivity::Get()->GetHistoryForTimeWindow(base::Minutes(30));

  return ToString(ComputeTabsOpened(events));
}

}  // namespace ads
