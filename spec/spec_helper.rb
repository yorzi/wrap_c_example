require 'rubygems'
require 'bundler/setup'

$:.unshift File.join(File.dirname(__FILE__), "..", "lib")

require 'wrap_c_example'

RSpec.configure do |config|
  config.order = 'random'
end
