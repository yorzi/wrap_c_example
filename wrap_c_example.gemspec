# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'wrap_c_example/version'

Gem::Specification.new do |spec|
  spec.name          = "wrap_c_example"
  spec.version       = WrapCExample::VERSION
  spec.authors       = ["Zac Hallett"]
  spec.email         = ["zac.hallett@gmail.com"]
  spec.description   = %q{Ruby wrapper for C example}
  spec.summary       = %q{Ruby wrapper for C example}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths << "ext/wrap_c_example"
  spec.extensions    << "ext/wrap_c_example/extconf.rb"

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "rspec"
  spec.add_development_dependency "rubygems-tasks"
end
