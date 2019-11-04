// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#define FML_USED_ON_EMBEDDER

#include "flutter/fml/delayed_task.h"

namespace fml {

DelayedTask::DelayedTask(size_t order,
                         fml::closure task,
                         fml::TimePoint target_time)
    : order_(order), task_(std::move(task)), target_time_(target_time) {}

DelayedTask::DelayedTask(const DelayedTask& other) = default;

DelayedTask::~DelayedTask() = default;

const fml::closure& DelayedTask::GetTask() const {
  return task_;
}

fml::TimePoint DelayedTask::GetTargetTime() const {
  return target_time_;
}

bool DelayedTask::operator>(const DelayedTask& other) const {
  if (target_time_ == other.target_time_) {
    return order_ > other.order_;
  }
  return target_time_ > other.target_time_;
}

}  // namespace fml
