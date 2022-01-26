/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/federated/federated_logs_util.h"

#include <cstdint>
#include <utility>

#include "base/check.h"
#include "base/i18n/time_formatting.h"
#include "base/strings/utf_string_conversions.h"
#include "base/time/time.h"
#include "base/values.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

namespace ads {

namespace {

const char kFederatedLogsEntryKey[] = "key";
const char kFederatedLogsEntryValue[] = "value";

}  // namespace

void AppendFederatedLogsKeyValue(const std::string& key,
                               const std::string& value,
                               base::Value* logs) {
  DCHECK(logs);
  DCHECK(logs->is_list());

  base::Value entry(base::Value::Type::DICTIONARY);
  entry.SetStringKey(kFederatedLogsEntryKey, key);
  entry.SetStringKey(kFederatedLogsEntryValue, value);
  logs->Append(std::move(entry));
}

absl::optional<std::string> GetFederatedLogsValueByKey(
    const base::Value& logs,
    const std::string& key) {
  DCHECK(logs.is_list());

  const std::string* value = nullptr;
  for (const base::Value& item : logs.GetList()) {
    DCHECK(item.is_dict());
    const std::string* found_key = item.FindStringKey(kFederatedLogsEntryKey);
    if (found_key && *found_key == key) {
      value = item.FindStringKey(kFederatedLogsEntryValue);
      break;
    }
  }

  return value ? *value : absl::optional<std::string>();
}

std::string ToString(const int64_t value) {
  return std::to_string(value);
}

std::string ToString(const bool value) {
  return value ? "true" : "false";
}

std::string ToString(const base::Time& time) {
  if (time.is_null())
    return {};
  return base::UTF16ToUTF8(base::TimeFormatShortDateAndTime(time));
}

}  // namespace ads
