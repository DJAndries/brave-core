/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/federated/log_entries/country_federated_logs_entry.h"

#include <cstdint>

#include "bat/ads/ads_client.h"
#include "bat/ads/internal/federated/federated_logs_util.h"
#include "brave/components/l10n/browser/locale_helper.h"
#include "brave/components/l10n/common/locale_util.h"
#include "bat/ads/pref_names.h"

namespace ads {

CountryFederatedLogsEntry::CountryFederatedLogsEntry() = default;

CountryFederatedLogsEntry::~CountryFederatedLogsEntry() = default;

FederatedLogsEntryType CountryFederatedLogsEntry::GetEntryType() const {
  return FederatedLogsEntryType::kCountry;
}

std::string CountryFederatedLogsEntry::GetKey() const {
  return "Country";
}

std::string CountryFederatedLogsEntry::GetValue() const {
  const auto locale = brave_l10n::LocaleHelper::GetInstance()->GetLocale();
  const auto country_code = brave_l10n::GetCountryCode(locale);

  return country_code;
}

}  // namespace ads
