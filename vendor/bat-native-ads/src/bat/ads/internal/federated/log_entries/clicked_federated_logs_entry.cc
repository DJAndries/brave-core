/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/federated/log_entries/clicked_federated_logs_entry.h"

#include <cstdint>

#include "bat/ads/ads_client.h"
#include "bat/ads/internal/federated/federated_logs_util.h"
#include "brave/components/l10n/browser/locale_helper.h"
#include "brave/components/l10n/common/locale_util.h"
#include "bat/ads/pref_names.h"

namespace ads {

ClickedFederatedLogsEntry::ClickedFederatedLogsEntry() = default;

ClickedFederatedLogsEntry::~ClickedFederatedLogsEntry() = default;

FederatedLogsEntryType ClickedFederatedLogsEntry::GetEntryType() const {
  return FederatedLogsEntryType::kClicked;
}

void ClickedFederatedLogsEntry::SetClicked(const bool clicked) {
  clicked_ = clicked;
}

std::string ClickedFederatedLogsEntry::GetKey() const {
  return "Clicked";
}

std::string ClickedFederatedLogsEntry::GetValue() const {
  return ToString(clicked_);
}

}  // namespace ads
