require "bundler/gem_tasks"
require "rubygems/package_task"
require "rake/extensiontask"
require "rake/testtask"
require "rspec/core/rake_task"
require "rake/clean"

CLEAN.include(
  "ext/wrap_c_example/*.o",
  "ext/wrap_c_example/*.bundle"
)

CLOBBER.include(
  "ext/wrap_c_example/Makefile",
  "pkg"
)

BUILD_DIR = 'build'

def gem_spec
  @gem_spec ||= Gem::Specification.load('wrap_c_example.gemspec')
end

Gem::PackageTask.new(gem_spec) do |pkg|
  pkg.need_zip = true
  pkg.need_tar = true
end

#Rake::TestTask.new do |t|
#  t.libs        = ['lib', 'spec']
#  t.warning     = true
#  t.verbose     = true
#  t.test_files  = FileList['spec/*_spec.rb']
#end

Rake::ExtensionTask.new("wrap_c_example_c", gem_spec) do |ext|
#  ext.name    = 'wrap_c_example'
  ext.ext_dir = './ext/wrap_c_example'
#  ext.lib_dir = 'lib/wrap_c_example'
  ext.tmp_dir = BUILD_DIR
  ext.config_script = "extconf.rb"
end

#task "copy:wrap_c_example" do |t|
#  %w[lib #{BUILD_DIR}/x86_64-darwin12.4.0/stage/lib]
#end

RSpec::Core::RakeTask.new(:spec)

task :build   => [:clean, :compile]

task :default => [:build, :spec]
