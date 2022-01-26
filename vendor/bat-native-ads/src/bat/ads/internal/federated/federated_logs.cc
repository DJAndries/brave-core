/* Copyright 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/federated/federated_logs.h"

#include <string>
#include <utility>

#include "base/check.h"
#include "base/json/json_writer.h"
#include "base/values.h"
#include "bat/ads/internal/federated/federated_logs_entry.h"
#include "bat/ads/internal/federated/federated_logs_util.h"
#include "bat/ads/internal/federated/log_entries/country_federated_logs_entry.h"
#include "bat/ads/internal/federated/log_entries/tabs_opened_federated_logs_entry.h"

namespace ads {

namespace {

FederatedLogs* g_federated_logs = nullptr;

}  // namespace

FederatedLogs::FederatedLogs() {
  DCHECK(!g_federated_logs);
  g_federated_logs = this;

  SetFederatedLogsEntry(std::make_unique<TabsOpenedFederatedLogsEntry>());
  SetFederatedLogsEntry(std::make_unique<CountryFederatedLogsEntry>());
}

FederatedLogs::~FederatedLogs() {
  DCHECK(g_federated_logs);
  g_federated_logs = nullptr;
}

// static
FederatedLogs* FederatedLogs::Get() {
  DCHECK(g_federated_logs);
  return g_federated_logs;
}

void FederatedLogs::SetFederatedLogsEntry(
    std::unique_ptr<FederatedLogsEntry> entry) {
  DCHECK(entry);
  FederatedLogsEntryType type = entry->GetEntryType();
  federated_logs_entries_[type] = std::move(entry);
}

std::string FederatedLogs::GetFederatedLogs() const {
  base::Value logs = CollectFederatedLogs();
  std::string json;
  const bool serialized = base::JSONWriter::Write(logs, &json);
  DCHECK(serialized);

  return json;
}

base::Value FederatedLogs::CollectFederatedLogs() const {
  base::Value logs(base::Value::Type::LIST);

  for (const auto& entry_pair : federated_logs_entries_) {
    FederatedLogsEntry* entry = entry_pair.second.get();
    AppendFederatedLogsKeyValue(entry->GetKey(), entry->GetValue(), &logs);
  }

  return logs;
}

}  // namespace ads
